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
#define double long double
using namespace std;
void solve(){  
    int n;
    scanf("%d",&n);
    int a[100005];
    vector<pii> v;
    for(int i = 0;i<n;i++){
     scanf("%d",&a[i]);
      //  a[i]=rand()%500000+1;
         v.pb(mp(a[i],1));
    }
   /* sort(a,a+n);
    for(int i = 0;i<n;i++){
        v.pb(mp(a[i],1));
    }*/
    for(int i = 1;i<n;i++){
        if(v.size()==2){
            printf("%d\n",v[1].x-v[0].x);
            return;
        }
        if(v.size()==1){
            printf("0\n");
            return;
        }
        vector<pii> v2;
        for(int j = 0;j<v.size();j++){
            if(v[j].y>1){
                v2.pb(mp(0,v[j].y-1));
            }
            if(j!=0){
                v2.pb(mp(v[j].x-v[j-1].x,1));
            }
        }
        sort(v2.begin(),v2.end());
        vector<pii> tmp;
        for(auto it:v2){
            if(tmp.empty()||it.x!=tmp.back().x)tmp.pb(it);
            else tmp.back().y+=it.y;
        }
        swap(v,tmp);
    }
    printf("%d\n",v[0].x);
}
int main(){
    int t=1;
    scanf("%d",&t);
    //printf("\"");
    while(t--){
        // cerr<<t<<endl;
        solve();
     //   cerr<<t<<endl;
    }
    
   // cerr<<cnt<<endl;
}
/*
*/