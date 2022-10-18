#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,vertex[22]={0},last=1;
    cin >> n;
    vertex[1]=1;
    set <int> edges;
    for(int i=2;i<=n;i++)
    {
        while(++last)
        {
            bool norm=true;
            for(int j=1;j<i;j++)
                if (edges.count(vertex[j]+last))
                {
                    norm=false;
                    break;
                }
            if (norm)
            {
                vertex[i]=last;
                for(int j=1;j<i;j++)
                    edges.insert(vertex[j]+last);
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (i==j) cout << "0";
            else cout << vertex[i]+vertex[j];
            if (j!=n) cout << " ";
        }
        cout << endl;
    }
    return 0;
}