#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

vector < vector <int> > g;
int color[1000002]={0};
vector <int> nums;

void dfs(int cur,int col)
{
    color[cur]=col;
    for(int i=0;i<g[cur].size();i++)
        if (!color[g[cur][i]]) dfs(g[cur][i],col);
}

multiset <int> f;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k,a,b;
    scanf("%d%d%d",&n,&m,&k);
    g.resize(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    int kol=0;
    for(int i=0;i<n;i++)
        if (!color[i]) dfs(i,++kol);
    nums.resize(kol,0);
    for(int i=0;i<n;i++)
        nums[color[i]-1]++;
    sort(nums.rbegin(),nums.rend());
    for(int i=0;i<nums.size();i++)
        if (nums[i]>k) nums[i]=k;
//  for(int i=0;i<nums.size();i++)
//      cout << nums[i] << "    ";
//  cout << endl;
    int sum=0,res=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        f.insert(nums[i]);
    }
    while(f.size()>1&&(sum/2)<f.size()-1)
    {
        multiset <int>::iterator it1,it2;
        it1=f.begin();
        it2=it1; it2++;
        sum-=(*it1); sum-=(*it2);
        sum+=min(k,(*it1)+(*it2));
        f.insert(min(k,(*it1)+(*it2)));
        f.erase(it1);
        res++;
        f.erase(it2);
    }
    cout << res << endl;
    return 0;
}