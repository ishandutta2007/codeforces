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
int cal2(set<pii> &s,int b,int t){
    int Max=0;
    for(auto it:s){
        if(it.x>=b&&it.y>=t){
            Max=max(Max,max(it.x-b,it.y-t));
        }
        else if(it.x<=b&&it.y<=t){
            Max=max(Max,max(b-it.x,t-it.y));
        }
        else{
            Max=max(Max,abs(b-it.x)+abs(t-it.y));
        }
    }
    if(t==0&&b==0)return 1e9;
    //printf("%d %d %d\n",b,t,Max);
    return Max;
}
pii cal(set<pii> &s,int b){
    int Min=0,Max=500005;
    while(Max>Min+5){
         int mid1=(Max*2+Min)/3,mid2=(Max+Min*2)/3;
         if(cal2(s,b,mid1)<cal2(s,b,mid2)){
             Min=mid2;
         }
         else{
             Max=mid1;
         }
    }
    int ans=1e9,ans2;
    for(int i = Max;i>=Min;i--){
        ans=min(ans,cal2(s,b,i));
        if(ans==cal2(s,b,i)){
            ans2=i;
        }
    }
    return mp(ans,ans2);
}
void solve(){
    set<pii> m;
    int n;
    scanf("%d",&n);
    //int Max=0,Min=-1;
    for(int i = 0;i<n;i++){
        char c[500005];
        scanf("%s",c);
        int B=0,N=0;
        for(int j = 0;c[j]!=0;j++){
            if(c[j]=='B')B++;
            else N++;
        }
        m.insert(mp(B,N));
       // printf("%d %d\n",B,N);
    //    Max=max(Max,b+n);
    }

    int Min=0,Max=500005;
    while(Max>Min+5){
        int mid1=(Max*2+Min)/3,mid2=(Max+Min*2)/3;
        pii p1=cal(m,mid1);
        pii p2=cal(m,mid2);
        /*printf("%d %d\n",Min,Max);
        printf("%d %d %d !\n",mid1,p1.x,p1.y);
        printf("%d %d %d\n",mid2,p2.x,p2.y);*/
        if(p1.x<p2.x){
            Min=mid2;
        }
        else{
            Max=mid1;
        }
    }
    int ans=1e9;
    pii ans2;
    for(int i = Max;i>=Min;i--){
        pii p=cal(m,i);
        if(ans>p.x){
            ans=p.x;
            ans2=mp(i,p.y);
        }
    }
    printf("%d\n",ans);
    for(int i =0;i<ans2.x;i++)printf("B");
    for(int i = 0;i<ans2.y;i++)printf("N");
    printf("\n");
}
int main(){
    int t=1;
   // scanf("%d",&t);
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