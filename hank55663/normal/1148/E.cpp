#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int n;
    scanf("%d",&n);
    pii s[300005];
    int t[300005];
    for(int i =0;i<n;i++){
        scanf("%d",&s[i].x);
        s[i].y=i+1;
    }
    for(int i = 0;i<n;i++)
        scanf("%d",&t[i]);
    sort(s,s+n);
    sort(t,t+n);
    LL ans=0;
    vector<int> go,from;
    for(int i = 0;i<n;i++){
        ans+=s[i].x-t[i];
        if(s[i].x>t[i])
        from.pb(i);
        else
        go.pb(i);
    }
    if(ans!=0){
        printf("NO\n");
    }
    else{
        vector<pair<pii,int> > ans;
        for(int i = 0,j=0;i<go.size()&&j<from.size();){
            int a=go[i],b=from[j];
            int Min=min(t[a]-s[a].x,s[b].x-t[b]);
            ans.pb(mp(mp(s[a].y,s[b].y),Min));
            s[a].x+=Min;
            s[b].x-=Min;
            if(s[a].x>s[b].x){
                printf("NO\n");
                return 0;
            }
            if(s[a].x==t[a])i++;
            if(s[b].x==t[b])j++;
        }
        printf("YES\n");
        printf("%d\n",ans.size());
        for(auto it:ans)
        printf("%d %d %d\n",it.x.x,it.x.y,it.y);
    }
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i

*/