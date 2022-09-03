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
bool cmp(const pair<pii,int> &p,const pair<pii,int> &q){
    return p.x.y>q.x.y;
}
bool cmp2(const pair<pii,int> &p,const pair<pii,int> &q){
    return p.x.x<q.x.x;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[300005];
    int b[300005];
    vector<pair<pii,int> > v1,v2;
    for(int i = 0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
        if(a[i]<b[i])
        v2.pb(mp(mp(a[i],b[i]),i+1));
        else
        v1.pb(mp(mp(a[i],b[i]),i+1));
    }
    sort(v1.begin(),v1.end(),cmp2);
    sort(v2.begin(),v2.end(),cmp);
    if(v1.size()>=v2.size()){
        printf("%d\n",v1.size());
        for(auto it:v1)
        printf("%d ",it.y);
        printf("\n");
    }
    else{
        printf("%d\n",v2.size());
        for(auto it:v2)
        printf("%d ",it.y);
        printf("\n");
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