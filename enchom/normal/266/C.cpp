#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

struct command
{
    Int instr;
    Int x,y;
};

Int rows[1001];
Int cols[1001];
Int table[1001][1001];
Int n;
Int totaldone=0;
vector<command> commands;
///Int whereisrow[1001];
///Int whereiscol[1001];

void SwapRows(Int a,Int b)
{
    Int i;
    Int d;
    
    d=rows[a];
    rows[a]=rows[b];
    rows[b]=d;
    
    for (i=1;i<=n;i++)
    {
        d=table[a][i];
        table[a][i]=table[b][i];
        table[b][i]=d;
    }
}

void SwapCols(Int a,Int b)
{
    Int i;
    Int d;
    
    d=cols[a];
    cols[a]=cols[b];
    cols[b]=d;
    
    for (i=1;i<=n;i++)
    {
        d=table[i][a];
        table[i][a]=table[i][b];
        table[i][b]=d;
    }
}

void solve(Int k)
{
    Int i;
    Int maxrow=-1,maxind;
    Int reach=1;
    command helper;
    
    if (k==0)
    return;
    
    for (i=1;i<=k;i++)
    {
        if (rows[i]>maxrow)
        {
            maxrow=rows[i];
            maxind=i;
        }
    }
    
    for (i=1;i<=k;i++)
    {
        if (table[maxind][i]==1 && i==reach)
        {
            reach++;
            continue;
        }
        
        if (table[maxind][i]==1)
        {
            SwapCols(reach,i);
            helper.x=reach;
            helper.y=i;
            helper.instr=2;
            
            commands.push_back(helper);
            
            reach++;
        }
    }
    
    if (maxind!=k)
    {
        SwapRows(maxind,k);
        helper.x=maxind;
        helper.y=k;
        helper.instr=1;
        
        commands.push_back(helper);
    }
    
    totaldone=totaldone+rows[maxind];
    
    if (totaldone>=n-1)
    return;
    
    if (cols[k]>0)
    {
        for (i=1;i<=k-1;i++)
        {
            if (cols[i]==0)
            {
                SwapCols(i,k);
                
                helper.x=i;
                helper.y=k;
                helper.instr=2;
                
                commands.push_back(helper);
            }
        }
    }
    
    
    for (i=1;i<=reach-1;i++)
    {
        cols[i]--;
    }
    
    solve(k-1);
}

int main()
{
    Int i;
    Int j;
    Int x,y;
    
    for (i=0;i<=1000;i++)
    {
        for (j=0;j<=1000;j++)
        table[i][j]=0;
    }
    
    for (i=0;i<=1000;i++)
    {
        rows[i]=0;
        cols[i]=0;
    }
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n-1;i++)
    {
        scanf("%I64d %I64d",&x,&y);
        
        rows[x]++;
        cols[y]++;
        
        table[x][y]=1;
    }
    
    solve(n);
    
    printf("%d\n",commands.size());
    
    for (i=0;i<commands.size();i++)
    {
        printf("%I64d %I64d %I64d\n",commands[i].instr,commands[i].x,commands[i].y);
    }
    return 0;
}