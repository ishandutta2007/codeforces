#include <bits/stdc++.h>

using namespace std;

int a, b, c;
vector<int> ans;

int pw(int x)
{
    int r=1;
    for(int i=0; i<a; i++)
        r*=x;
    return r;
}

void check(int x, int y)
{
    int ox=x;
    int s=0;
    while(x>0)
        s+=x%10, x/=10;
    if(s==y)
        ans.push_back(ox);
}

int main()
{
    cin>>a>>b>>c;
    for(int i=1; i<=81; i++)
    {
        double d=b*pow((double)i, (double)a)+c;
        if(d>0 && d<1e9)
            check(b*pw(i)+c, i);
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto it: ans)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}