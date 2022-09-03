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
    char s[55];
    scanf("%s",s);
    sort(s,s+strlen(s));
    reverse(s,s+strlen(s));
    map<char,int> m;
    vector<pair<char,int> > v;
    for(int i = 0;s[i]!=0;i++){
        m[s[i]]++;
    }
    for(auto it:m)v.pb(it);
    reverse(v.begin(),v.end());
    int n;
    scanf("%d",&n);
    int b[55];
    for(int i = 0;i<n;i++){
        scanf("%d",&b[i]);
    }
    char ans[55];
    MEM(ans);
    queue<int> q,q1;
    for(int i = 0;i<n;i++){
        if(b[i]==0)q.push(i);
    }
    int now=0;
    while(!q.empty()){
        //printf("%d %d\n",q.size(),v[now].y);
        while(v[now].y<q.size())now++;
      //  printf("%c %d\n",v[now].x,now);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans[x]=v[now].x;
            for(int i = 0;i<n;i++){
                if(b[i]){
                b[i]-=abs(i-x);
                
                if(b[i]==0)q1.push(i);
                }
            }
        }
        now++;
        swap(q,q1);
    }
    printf("%s\n",ans);
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