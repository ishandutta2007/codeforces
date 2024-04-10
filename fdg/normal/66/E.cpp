#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>

#define ll long long

using namespace std;

vector <int> v,nums;
vector <int> a,b;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    vector <int> ans;
    int n;
    cin >> n;
    v.resize(n);
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        v[i]=a[i]-b[i];
    }
    nums=v;
    for(int i=1;i<n;i++)
        v[i]+=v[i-1];
    int mn=1000000000;
    for(int i=0;i<n;i++)
        if (v[i]<mn) mn=v[i];
    int curs=0;
    for(int i=0;i<n;i++)
    {
        curs-=nums[i];
        if (curs+mn>=0) ans.push_back((i+1)%n);
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int tmp=b[0];
    b.erase(b.begin());
    b.push_back(tmp);
    for(int i=0;i<n;i++)
        v[i]=a[i]-b[i];
    nums=v;
    for(int i=1;i<n;i++)
        v[i]+=v[i-1];
    mn=1000000000;
    for(int i=0;i<n;i++)
        if (v[i]<mn) mn=v[i];
    curs=0;
    int curp=n-1;
    for(int i=0;i<n;i++)
    {
        curs-=nums[i];
        curp--; if (curp<0) curp=n-1;
        if (curs+mn>=0) ans.push_back(curp);
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    cout << ans.size() << endl;
    if (ans.size()>0)
    {
        cout << ans[0]+1;
        for(int i=1;i<ans.size();i++)
            cout << " " << ans[i]+1;
        cout << endl;
    }
    return 0;
}