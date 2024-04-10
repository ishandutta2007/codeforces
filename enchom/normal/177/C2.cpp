#include <iostream>
#include <vector>
using namespace std;

bool invited[2001];
bool hated[2001];
int tail[2001],tL=0,uk;
vector<int> friends[2001];
vector<int> enemys[2001];

int main()
{
    int n;
    int i,j,in;
    int k,m,a,b;
    int guy;
    bool flag;
    int maX=0;
    
    cin>>n;
    cin>>k;
    
    for (i=1;i<=k;i++)
    {
        cin>>a>>b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    cin>>m;
    for (i=1;i<=m;i++)
    {
        cin>>a>>b;
        enemys[a].push_back(b);
        enemys[b].push_back(a);
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            invited[j]=false;
            hated[j]=false;
        }
        tL=0;
        uk=1;
        
        invited[i]=true;
        tL++;
        tail[1]=i;
        flag=false;
        
        while (uk<=tL)
        {
            guy=tail[uk];
            for (j=0;j<friends[guy].size();j++)
            {
                if (!invited[friends[guy][j]])
                {
                    if (hated[friends[guy][j]])
                    {
                        flag=true;
                        break;
                    }
                    else
                    {
                        invited[friends[guy][j]]=true;
                        tL++;
                        tail[tL]=friends[guy][j];
                    }
                }
            }
            
            if (flag)
            break;
            
            for (j=0;j<enemys[guy].size();j++)
            {
                if (invited[enemys[guy][j]])
                {
                    flag=true;
                    break;
                }
                hated[enemys[guy][j]]=true;
            }
            
            if (flag)
            break;
            
            uk++;
        }
        if (!flag)
        {
            if (tL>maX)
            {
                maX=tL;
            }
            
        }
    }
    cout<<maX<<endl;
    return 0;
}