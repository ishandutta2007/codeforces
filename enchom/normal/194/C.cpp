#include <iostream>
using namespace std;

struct dtail
{
    int x,y;
};

char sheet[53][53];
int n,m;

bool BFS()
{
    dtail tail[2502];
    int tL=0;
    int uk=1,cX,cY,X,Y;
    bool TFO[53][53];
    int i,j;
    bool flag=false;
    for (i=0;i<=50;i++)
    {
        for (j=0;j<=50;j++)
        TFO[i][j]=false;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (sheet[i][j]=='#')
            {
                tL++;
                tail[tL].x=i;
                tail[tL].y=j;
                TFO[i][j]=true;
                flag=true;
                break;
            }
        }
        if (flag)
        break;
    }
    while (uk<=tL)
    {
        cX=tail[uk].x;
        cY=tail[uk].y;
        
        X=cX+1;
        Y=cY;
        if (sheet[X][Y]=='#' && !TFO[X][Y])
        {
            tL++;
            tail[tL].x=X;
            tail[tL].y=Y;
            TFO[X][Y]=true;
        }
        
        
        X=cX-1;
        Y=cY;
        if (sheet[X][Y]=='#' && !TFO[X][Y])
        {
            tL++;
            tail[tL].x=X;
            tail[tL].y=Y;
            TFO[X][Y]=true;
        }
        
        
        X=cX;
        Y=cY-1;
        if (sheet[X][Y]=='#' && !TFO[X][Y])
        {
            tL++;
            tail[tL].x=X;
            tail[tL].y=Y;
            TFO[X][Y]=true;
        }
        
        
        X=cX;
        Y=cY+1;
        if (sheet[X][Y]=='#' && !TFO[X][Y])
        {
            tL++;
            tail[tL].x=X;
            tail[tL].y=Y;
            TFO[X][Y]=true;
        }
        
        uk++;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (!TFO[i][j] && sheet[i][j]=='#')
            {
                return false;
            }
            
        }
    }
    return true;
}

int main()
{
    int i,j;
    int dies=0;
    
    cin>>n>>m;
    for (i=0;i<=52;i++)
    {
        for (j=0;j<=52;j++)
        {
            sheet[i][j]='.';
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cin>>sheet[i][j];
            if (sheet[i][j]=='#')
            dies++;
        }
    }
    if (dies==1 || dies==2)
    {
        cout<<-1<<endl;
        return 0;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (sheet[i][j]=='#')
            {
                sheet[i][j]='.';
                if ( !BFS() )
                {
                    cout<<1<<endl;
                    return 0;
                }
                sheet[i][j]='#';
            }
        }
    }
    cout<<2<<endl;
    return 0;
}