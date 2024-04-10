#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#define fr(a,b,c) for(a=b;a<=c;a++)
#define frr(a,b,c) for(a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

int n,a,b,z,re[111111];
vector<pii> c;

bool cmp(pii i,pii j)
{
    return i.first>j.first || (i.first==j.first && i.second*z<j.second*z); 
}

int main()
{
    int i,x;
    cin >> n >> a >> b;
    if (a==b)
    {
       fr(i,1,a) printf("1 ");
       fr(i,1,b) printf("2 ");
       puts("");
       return 0;      
    }
    if (a>b) swap(a,b),z=-1;
    else z=1;
    fr(i,1,n)
    {
       scanf("%d",&x);
       c.pb(mp(x,i));
    }
    sort(c.begin(),c.end(),cmp);
    memset(re,-1,sizeof(re));
    fr(i,0,a-1) re[c[i].second]=1;
    fr(i,1,n)
      if (re[i]*z>0) printf("1 ");
      else printf("2 ");
    puts("");
    //system("pause");
    return 0;
}