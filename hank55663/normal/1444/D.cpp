#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define MXN 250005//250005
using namespace std;
bitset<MXN> b1[501],b2[501];
void solve(){ 
    srand(time(NULL));  
    int h;
    vector<int> l;
    int suml=0;
    int v;
    vector<int> p;
    int sump=0;
    scanf("%d",&h);
    for(int i=  0;i<h;i++){
        int x=i+1;
        scanf("%d",&x);
        l.pb(x);
        suml+=x;
    }
    scanf("%d",&v);
    for(int i = 0;i<v;i++){
        int x=i+1;//1000;//rand()%1000+1;
        scanf("%d",&x);
        p.pb(x);
        sump+=x;
    }
    if(h!=v||suml%2||sump%2){
        printf("No\n");
        return;
    }
    for(int i = 0;i<=h;i++){
        b1[i]=0;
        b2[i]=0;
    }
    b1[0][0]=1;
    for(int i = 0;i<h;i++){
        b1[i+1]=b1[i]|(b1[i]<<l[i]);
    // cout<<b1[i+1][0]<<endl;
    }
    b2[0][0]=1;
    for(int i = 0;i<v;i++){
        b2[i+1]=b2[i]|(b2[i]<<p[i]);
        //cout<<b2[i+1][0]<<endl;
    }
   // cout<<b1[h]<<"\n"<<b2[v]<<"\n";
    if(b1[h][suml/2]&&b2[v][sump/2]){
        printf("Yes\n");
        vector<int> l1,l2,p1,p2;
        int now=suml/2;
        for(int j =h-1;j>=0;j--){
            if(now>=l[j]&&b1[j][now-l[j]]){
                l1.pb(l[j]);
                now-=l[j];
            }
            else{
                l2.pb(l[j]);
            }
        }
        now=sump/2;
        for(int j = h-1;j>=0;j--){
            if(now>=p[j]&&b2[j][now-p[j]]){
                p1.pb(p[j]);
                now-=p[j];
            }
            else{
                p2.pb(p[j]);
            }
        }
        sort(l1.begin(),l1.end());
        
        sort(l2.begin(),l2.end());
       
        if(l1.size()>l2.size())swap(l1,l2);
        sort(p1.begin(),p1.end());
        sort(p2.begin(),p2.end());
        if(p1.size()>p2.size())swap(p1,p2);
        if(l1.size()<p1.size()){
            reverse(l1.begin(),l1.end());
             reverse(l2.begin(),l2.end());
            for(auto it:l2)l1.pb(-it);
            for(auto it:p2)p1.pb(-it);
            printf("0 0\n");
            int x=0,y=0;
            for(int i = 0;i<l1.size();i++){
                x+=l1[i];
                printf("%d %d\n",x,y);
                y+=p1[i];
                if(i!=l1.size()-1)
                printf("%d %d\n",x,y);
            }
        }
        else{
             reverse(p1.begin(),p1.end());
             reverse(p2.begin(),p2.end());
            for(auto it:l2)l1.pb(-it);
            for(auto it:p2)p1.pb(-it);
            printf("0 0\n");
            int x=0,y=0;
            for(int i = 0;i<l1.size();i++){
                y+=p1[i];
                printf("%d %d\n",x,y);
                x+=l1[i];
                if(i!=l1.size()-1)
                printf("%d %d\n",x,y);
            }
        }
    }
    else
    printf("No\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
11 4 12
1 1 1 1
AABB
.AB.
CCDD
.CD.
EEFF
.EF.
GGHH
.GH.
IIJJ
.IJ.
KKLL

12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/