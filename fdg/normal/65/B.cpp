#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,last=1000,a;
    cin >> n;
    vector <int> ans;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        vector <int> v;
        int k=a,next=2012,step[]={1,10,100,1000};
        while(k>0)
        {
            v.push_back(k%10);
            k/=10;
        }
        for(int t=0;t<4;t++)
        {
            for(int j=(t==3 ? 1 : 0);j<10;j++)
            {
                int cur=a-step[t]*v[t]+step[t]*j;
                if (cur<next&&cur>=last) next=cur;
            }
        }
        if (next!=2012) ans.push_back(next);
        else
        {
            cout << "No solution\n";
            return 0;
        }
        last=next;
    }
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << endl;
    return 0;
}