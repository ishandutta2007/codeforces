#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MEM(x) memset(x,0,sizeof(x)
int main(){
    vector<pii> v;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            v.pb(mp(i,j));
        }
    }
    vector<pii> ans;
    int l =0,r=v.size()-1;
    while(l<r){
        printf("%d %d\n",v[l].x,v[l].y);
        printf("%d %d\n",v[r].x,v[r].y);
        //ans.pb(v[l]);
        //ans.pb(v[r]);
        l++;r--;
    }
    if(l==r){
        printf("%d %d\n",v[l].x,v[l].y);
        //ans.pb(v[l]);
    }
   // set<pii> s;
   // for(int i = 1;i<ans.size();i++){
    //    s.insert(mp(ans[i].x-ans[i-1].x,ans[i].y-ans[i-1].y));
  //  }
   // printf("%d\n",s.size());
  //  assert(s.size()==n*m-1);
}
/*
m3->m2->m->m4
0 1 2 3 453*
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/