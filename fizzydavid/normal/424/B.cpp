#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define y0 qgoiqoeinfoiqwef
#define y1 vmpoqmeppjofaqoi
#define yn qoigmnioqonfopiq
#define ff first
#define ss second
int n,s;
vector<pair<int,int> >a;
int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        int x,y,k;
        cin>>x>>y>>k;
        a.push_back(make_pair(x*x+y*y,k));
    }
    sort(a.begin(),a.end());
    double r;
    for(int i=0;i<a.size()&&s<1000000;i++)
    {
        s+=a[i].ss;
        r=a[i].ff;
    }
    if(s>=1000000)
    {
        cout<<sqrt(r);
    }
    else cout<<-1;
    return 0;
}