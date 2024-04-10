#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-7
using namespace std;
int vis[1<<10][10];
string ans;
string s[10];
bool go(int i,int n,int m,int mask=0,string str=""){
    if(i==m){
        ans=str;
        return true;
    }
    if(vis[mask][i])return false;
    vis[mask][i]=1;
    for(int j=0;j<26;j++){
        int ma=mask;
        int ok=1;
        for(int k = 0;k<n;k++){
            if(s[k][i]!=j+'a'){
                if(ma&(1<<k))ok=0;
                else ma|=1<<k;
            }
        }
        if(ok){
            if(go(i+1,n,m,ma,str+(char)(j+'a')))return true;
        }
    }
    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);

        MEM(vis);
        for(int i = 0;i<n;i++){
            cin>>s[i];
        }
        if(go(0,n,m)){
            printf("%s\n",ans.c_str());
        }
        else{
            printf("-1\n");
        }
    }
}
/*
2 11 14
9 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
3**5+3**5-2**5
000111222
001112220
*/