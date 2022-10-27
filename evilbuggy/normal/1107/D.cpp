#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

map<char, int> hsh;

void preprocess(){
    for(int i = 0; i < 10; i++){
        hsh[char(i + '0')] = i;
    }
    for(int j = 10; j < 16; j++){
        hsh[char(j - 10 + 'A')] = j;
    }
}

int a[5250][5250];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    preprocess();
    memset(a, 0, sizeof(a));
    int n;
    cin>>n;
    string s;
    for(int i = 1; i <= n; i++){
        cin>>s;
        for(int j = 0; j < s.size(); j++){
            int x = hsh[s[j]];
            for(int k = 0; k < 4; k++){
                if(x&(1<<k))a[i][4*j + 4 - k] = 1;
                else a[i][4*j + 4 - k] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] += (a[i-1][j] + a[i][j-1] - a[i-1][j-1]);
        }
    }
    for(int k = n; k >= 1; k--){
        if(n%k != 0)continue;
        bool pos = true;
        for(int x = k; x <= n; x += k){
            for(int y = k; y <= n; y += k){
                int tmp = a[x][y] - a[x-k][y] - a[x][y-k] + a[x-k][y-k];
                if(tmp != k*k && tmp != 0){
                    pos = false;
                    break;
                }
            }
            if(!pos)break;
        }
        if(pos){
            cout<<k<<endl;
            return 0;
        }
    }
}