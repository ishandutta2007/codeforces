#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
void solve(){
    char c[105];
    vector<int> v;
    scanf("%s",c);
    int cnt=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='0'){
            if(cnt)v.pb(cnt);
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    if(cnt)v.pb(cnt);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int ans=0;
    for(int i = 0;i<v.size();i+=2){
        ans+=v[i];
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/