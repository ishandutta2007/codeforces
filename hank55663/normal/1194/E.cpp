#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
int S[10005];
void add(int x,int k){
    for(int i  =x;i<10005;i+=i&-i){
        S[i]+=k;     
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int,pii> > H,V;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1+=5001;
        x2+=5001;
        if(y1>y2)
        swap(y1,y2);
        if(x1>x2)
        swap(x1,x2);
        if(x1==x2){
            V.pb(mp(x1,mp(y1,y2)));
        }
        else{
            //printf("? %d %d %d\n",y1,x1,x2);
            H.pb(mp(y1,mp(x1,x2)));
        }
    }
    sort(H.begin(),H.end());
    LL ans=0;
    for(int i = 0;i<H.size();i++){
        auto it=H[i];
        priority_queue<pii,vector<pii> ,greater<pii> > pq;
        for(auto it2:V){
            if(it2.x>=it.y.x&&it2.x<=it.y.y&&it2.y.x<=it.x&&it2.y.y>=it.x){
                add(it2.x,1);
                pq.push(mp(it2.y.y,it2.x));
            }
        }
        for(int j = i+1;j<H.size();j++){
            auto it2=H[j];
            while(!pq.empty()&&pq.top().x<it2.x){
                add(pq.top().y,-1);
                pq.pop();
            }
            int res=query(it2.y.y)-query(it2.y.x-1);
            ans+=res*(res-1)/2;
        }
        while(!pq.empty()){
            add(pq.top().y,-1);
            pq.pop();
        }
        //printf("%d %d %d %lld\n",it.x,it.y.x,it.y.y,ans);
    }
    printf("%lld\n",ans);
}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */