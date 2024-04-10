#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    char c[3][200005];
    for(int i = 0;i<3;i++){
        scanf("%s",c[i]);
    }
    int idx[3]={0,0,0};
    string ans;
    n*=2;
    while(idx[0]!=n&&idx[1]!=n&&idx[2]!=n){
        int cnt[2]={0,0};
        for(int j=0;j<3;j++){
            cnt[c[j][idx[j]]-'0']++;
        }
        if(cnt[0]>cnt[1]){
            ans+='0';
            for(int j =0;j<3;j++){
                if(c[j][idx[j]]=='0')idx[j]++;
            }
        }
        else{
            ans+='1';
             for(int j =0;j<3;j++){
                if(c[j][idx[j]]=='1')idx[j]++;
            }
        }
    }
    if(idx[0]==n){
        if(idx[1]>idx[2]){
            for(int j = idx[1];j<n;j++)ans+=c[1][j];
        }
        else{
            for(int j = idx[2];j<n;j++)ans+=c[2][j];
        }
    }
    else if(idx[1]==n){
         if(idx[0]>idx[2]){
            for(int j = idx[0];j<n;j++)ans+=c[0][j];
        }
        else{
            for(int j = idx[2];j<n;j++)ans+=c[2][j];
        }
    }
    else{
         if(idx[1]>idx[0]){
            for(int j = idx[1];j<n;j++)ans+=c[1][j];
        }
        else{
            for(int j = idx[0];j<n;j++)ans+=c[0][j];
        }
    }
    printf("%s\n",ans.c_str());
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/