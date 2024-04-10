#include <bits/stdc++.h>

using namespace std;

// bool overflow(long long int a, long long int b){
//     long long int c = a*b;
//     return (c/a) != b;
// }

long long int power(long long int n, int p){
    if(p == 1)return n;
    long long int s, t = power(n, p/2);
    if(t == -1)return -1;
    if(__builtin_mul_overflow(t,t,&s))return -1;
    if(p%2 == 0){
        return s;
    }
    if(__builtin_mul_overflow(s,n,&t))return -1;
    return t;
}

long long int countFunc(long long int n, int p){
    long long int tmp = powl(n, 1.0/p);
    tmp = max(1LL, tmp - 5);
    while(true){
        long long int t = power(tmp + 1, p);
        if(t == -1 || t > n)break;
        tmp++;
    }
    return tmp;
}

int calcMob(int n){
    int tmp = 2;
    vector<int> pw;
    while(n > 1){
        if(n%tmp == 0){
            int cnt = 0;
            while(n%tmp == 0){
                n /= tmp;
                cnt++;
            }
            pw.push_back(cnt);
        }
        tmp++;
    }
    for(size_t i = 0; i < pw.size(); i++){
        if(pw[i] > 1)return 0;
    }
    if(pw.size()%2 == 0)return 1;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int mob[64];
    for(int i = 1; i < 64; i++){
        mob[i] = calcMob(i);
    }
    while(t--){
        long long int n;
        cin>>n;
        long long int cnt[64];
        for(int i = 2; i < 64; i++){
            cnt[i] = countFunc(n, i) - 1;
        }
        cnt[1] = n - 1;
        long long int ans = 0;
        for(int i = 1; i < 64; i++){
            ans += cnt[i]*mob[i];
        }
        cout<<ans<<endl;
    }
}