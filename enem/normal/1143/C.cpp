#include <iostream>
#include <vector>
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define PB push_back


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    freopen("output.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */


    int n;
    cin>>n;
    int p[n];
    int c[n];
    vector<int> nd[n];
    REP(i,0,n)
    {
        int t;
        cin>>t>>c[i];
        if(t!=-1) p[i]=t-1;
        else p[i]=t;
        if(p[i]!=-1)
        {
            nd[p[i]].PB(i);
        }
    }
    int f=0;
    REP(i,0,n)
    {
        if(p[i]==-1) continue;
        if(c[i]==1)
        {
            int f2=0;
            REP(j,0,nd[i].size())
            {
                if(c[nd[i][j]]!=1)
                {
                    f2=1;
                    break;
                }
            }
            if(f2==0)
            {
                cout<<i+1<<' ';
                /*
                REP(j,0,nd[i].size())
                {
                    nd[p[i]].PB(nd[i][j]);
                    p[nd[i][j]]=p[i];
                }
                REP(j,0,nd[p[i]].size())
                {
                    if(nd[p[i]][j]==i)
                    {
                        nd[p[i]].erase(nd[p[i]].begin()+j);
                        break;
                    }
                }
                nd[i].clear();
                */
                p[i]=-1;
                f=1;
            }
        }
    }
    if(f==0)
    {
        cout<<-1;
    }

    return 0;
}