#include<bits/stdc++.h>
using namespace std;
map<string,int> m,m1;
int main(){
    string name[1010];int mark[1010];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>name[i]>>mark[i];
        m[name[i]]+=mark[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        maxn=max(maxn,m[name[i]]);
    }
    for(int i=1;i<=n;i++){
        m1[name[i]]+=mark[i];
        if(m1[name[i]]>=maxn&&m[name[i]]>=maxn){
            cout<<name[i];
            return 0;
        }
    }
    return 0;
}