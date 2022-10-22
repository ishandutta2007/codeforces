#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,t,a[100005];
vector<int> Odd,Even;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        Odd.clear();
        Even.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2==0) Even.push_back(a[i]);
            if(a[i]%2==1) Odd.push_back(a[i]);
        }
        bool flag=true;
        for(int i=1;i<Odd.size();i++)
        {
            if(Odd[i]<Odd[i-1]) flag=false;
        }
        for(int i=1;i<Even.size();i++)
        {
            if(Even[i]<Even[i-1]) flag=false;
        }
        printf(flag ? "Yes\n" : "No\n");
    }
}