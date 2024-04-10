//EM NOME DE ABELLA
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

#define MN 490

using namespace std;

bool visit1[MN],visit2[MN];
vector <int> ida[MN];
vector <int> volta[MN];

void dfsida(int node)
{
        if(visit1[node]==true) return;
        visit1[node]=true;
        for(int i=0;i<ida[node].size();i++)
        {
                dfsida(ida[node][i]);
        }
}

void dfsvolta(int node)
{
        if(visit2[node]==true) return;
        visit2[node]=true;
        for(int i=0;i<volta[node].size();i++)
        {
                dfsvolta(volta[node][i]);
        }
}

int main()
{
    int h,v,i,j;
    char direcao;
    scanf("%d %d ",&h,&v);
    for(i=0;i<h;i++)
    {
                    scanf("%c",&direcao);
                    for(j=0;j<v-1;j++)
                    {
                                    if(direcao=='>')
                                    {
                                                    ida[(i*v)+j].push_back((i*v)+j+1);
                                                    volta[(i*v)+j+1].push_back((i*v)+j);
                                    }
                                    else if(direcao=='<')
                                    {
                                                    ida[(i*v)+j+1].push_back((i*v)+j);
                                                    volta[(i*v)+j].push_back((i*v)+j+1);
                                    }
                    }
    }
    scanf("%c",&direcao);
    
    
    for(j=0;j<v;j++)
    {
                    scanf("%c",&direcao);
                    for(i=0;i<h-1;i++)
                    {
                                    if(direcao=='^')
                                    {
                                                    ida[((i+1)*v)+j].push_back((i*v)+j);
                                                    volta[(i*v)+j].push_back(((i+1)*v)+j);
                                    }
                                    else if(direcao=='v')
                                    {
                                                    ida[(i*v)+j].push_back(((i+1)*v)+j);
                                                    volta[((i+1)*v)+j].push_back((i*v)+j);
                                    }
                    }
    }
    scanf("%c",&direcao);
    //for(i=0;i<v*h;i++) for(j=0;j<volta[i].size();j++) printf("%d pra %d\n",i,volta[i][j]);
    memset(visit1,0,sizeof(visit1));
    memset(visit2,0,sizeof(visit2));
    int ok=1;
    dfsida(0);
    for(i=0;i<v*h;i++) if(visit1[i]==false) ok=0;
    dfsvolta(0);
    for(i=0;i<v*h;i++) if(visit2[i]==false) ok=0;
    if(ok==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}