#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int q[105], r[105], p[105], s[105];

bool check(){
    for(int i = 1; i <= n; i++){
        if(p[i] != s[i])return false;
    }
    return true;
}

void applyPerm(bool flg){
    if(flg){
        for(int i = 1; i <= n; i++){
            r[i] = p[q[i]];
        }
        for(int i = 1; i <= n; i++){
            p[i] = r[i];
            // cout<<q[i]<<" ";
        }
        // cout<<endl;
    }else{
        for(int i = 1; i <= n; i++){
            r[q[i]] = p[i];
        }
        for(int i = 1; i <= n; i++){
            p[i] = r[i];
            // cout<<r[i]<<" ";
        }
        // cout<<endl;
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>q[i];
        p[i] = i;
    }
    for(int i = 1; i <= n; i++){
        cin>>s[i];
    }
    int backMax = 1;
    applyPerm(false);
    while(!check() && backMax <= k){
        applyPerm(false);
        backMax++;
    }
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    int forwMax = 1;
    applyPerm(true);
    while(!check() && forwMax <= k){
        applyPerm(true);
        forwMax++;
    }
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    if(check()){
        cout<<"NO"<<endl;
        return 0;
    }
    // cout<<forwMax<<" "<<backMax<<endl;
    if(k == forwMax || k == backMax){
        cout<<"YES"<<endl;
    }else if(k < forwMax && k < backMax){
        cout<<"NO"<<endl;
    }else if(k < forwMax && k > backMax){
        if(k%2 == backMax%2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else if(k < backMax && k > forwMax){
        if(k%2 == forwMax%2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else if(forwMax == 1 && backMax == 1){
        cout<<"NO"<<endl;
    }else if(forwMax == 1 && backMax > 1){
        cout<<"YES"<<endl;
    }else if(backMax == 1 && forwMax > 1){
        cout<<"YES"<<endl;
    }else if(k%2 == forwMax%2 || k%2 == backMax%2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}