#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int n,m;
int grid[32][32];
int goal[32][32];
vector< pair<int,int> > moves;
bool blocked[32][32];

int ctr1[1001];
int ctr2[1001];

int begx=1,begy=1;
int curx,cury;

pair<int,int> Path[1001];
int L=0;

pair<int,int> BlockPath[1001];
int bL=0;

bool FoundPath=false;
int UTFO[32][32];
int Key=1;

bool First=true;

void GetPath(int cx,int cy,int gx,int gy)
{
    //cout<<"Currently at "<<cx<<";"<<cy<<" trying to reach "<<gx<<" "<<gy<<endl;

    if (UTFO[cx][cy]==Key)
    return;

    if (cx==gx && cy==gy)
    {
        FoundPath=true;
        return;
    }

    UTFO[cx][cy]=Key;

    int mx,my;

    if (cx<gx)
    mx=1;
    else if (cx>gx)
    mx=-1;
    else
    mx=0;

    if (cy<gy)
    my=1;
    else if (cy>gy)
    my=-1;
    else
    my=0;

    //cout<<mx<<".;."<<my<<endl;

    if (!blocked[cx+mx][cy+my])
    {
        L++;
        Path[L]=make_pair(cx+mx,cy+my);
        GetPath(cx+mx,cy+my,gx,gy);
        if (FoundPath)
        return;
        L--;
    }

    if (mx!=0)
    {
        if (!blocked[cx+mx][cy])
        {
            L++;
            Path[L]=make_pair(cx+mx,cy);
            GetPath(cx+mx,cy,gx,gy);
            if (FoundPath)
            return;
            L--;
        }
    }

    ///

    if (my!=0)
    {
        if (!blocked[cx][cy+my])
        {
            L++;
            Path[L]=make_pair(cx,cy+my);
            GetPath(cx,cy+my,gx,gy);
            if (FoundPath)
            return;
            L--;
        }
    }

    ///

    if (mx==0)
    {
        if (!blocked[cx-1][cy+my])
        {
            L++;
            Path[L]=make_pair(cx-1,cy+my);
            GetPath(cx-1,cy+my,gx,gy);
            if (FoundPath)
            return;
            L--;
        }

        if (!blocked[cx+1][cy+my])
        {
            L++;
            Path[L]=make_pair(cx+1,cy+my);
            GetPath(cx+1,cy+my,gx,gy);
            if (FoundPath)
            return;
            L--;
        }
    }

    ///

    if (my==0)
    {
        if (!blocked[cx+mx][cy-1])
        {
            L++;
            Path[L]=make_pair(cx+mx,cy-1);
            GetPath(cx+mx,cy-1,gx,gy);
            if (FoundPath)
            return;
            L--;
        }

        if (!blocked[cx+mx][cy+1])
        {
            L++;
            Path[L]=make_pair(cx+mx,cy+1);
            GetPath(cx+mx,cy+1,gx,gy);
            if (FoundPath)
            return;
            L--;
        }
    }

    if (!blocked[cx-1][cy+my])
    {
        L++;
        Path[L]=make_pair(cx-1,cy+my);
        GetPath(cx-1,cy+my,gx,gy);
        if (FoundPath)
        return;
        L--;
    }

    if (!blocked[cx+1][cy+my])
    {
        L++;
        Path[L]=make_pair(cx+1,cy+my);
        GetPath(cx+1,cy+my,gx,gy);
        if (FoundPath)
        return;
        L--;
    }

    if (!blocked[cx+mx][cy-1])
    {
        L++;
        Path[L]=make_pair(cx+mx,cy-1);
        GetPath(cx+mx,cy-1,gx,gy);
        if (FoundPath)
        return;
        L--;
    }

    if (!blocked[cx+mx][cy+1])
    {
        L++;
        Path[L]=make_pair(cx+mx,cy+1);
        GetPath(cx+mx,cy+1,gx,gy);
        if (FoundPath)
        return;
        L--;
    }

    return;
}

void SWAP(int x1,int y1,int x2,int y2)
{
    int k=grid[x1][y1];
    grid[x1][y1]=grid[x2][y2];
    grid[x2][y2]=k;
    return;
}

void MovePointer(int x,int y)
{
    int i;

    //cout<<"Moving pointer from "<<curx<<";"<<cury<<" to "<<x<<";"<<y<<endl;

    L=0;
    FoundPath=false;
    Key++;
    GetPath(curx,cury,x,y);

    for (i=1;i<=L;i++)
    {
        moves.push_back( make_pair(Path[i].first,Path[i].second) );

        SWAP(curx,cury,Path[i].first,Path[i].second);

        curx=Path[i].first;
        cury=Path[i].second;
    }

    return;
}

void MoveBlock(int x1,int y1,int x2,int y2)
{
    int i;
    int bx=x1,by=y1;

    L=0;
    FoundPath=false;
    Key++;
    GetPath(x1,y1,x2,y2);

    bL=L;
    //cout<<"Path of length "<<L<<endl;
    for (i=1;i<=L;i++)
    {
        //cout<<Path[i].first<<";"<<Path[i].second<<endl;
        BlockPath[i]=Path[i];
    }

    for (i=1;i<=bL;i++)
    {
        //cout<<"Moving the block to "<<BlockPath[i].first<<" "<<BlockPath[i].second<<endl;

        blocked[bx][by]=true;
        MovePointer(BlockPath[i].first,BlockPath[i].second);
        blocked[bx][by]=false;
        MovePointer(bx,by);

        bx=BlockPath[i].first;
        by=BlockPath[i].second;
    }

    return;
}

void RemoveLine()
{
    int i,j,in;
    int s;
    int x,y;

    //cout<<"Removing line "<<n<<endl;
    //cout<<endl;

    for (i=1;i<=m;i++)
    {
        ///Removing [n,i]
        x=-1;
        y=-1;

        for (j=1;j<=n;j++)
        {
            if (j!=n)
            s=1;
            else
            s=i;

            for (in=s;in<=m;in++)
            {
                if (j==curx && in==cury)
                continue;

                if (grid[j][in]==goal[n][i])
                {
                    x=j;
                    y=in;
                    break;
                }
            }

            if (x!=-1)
            break;
        }

        //cout<<"Trying to fill "<<n<<";"<<i<<" with the block at "<<x<<";"<<y<<"("<<grid[x][y]<<")"<<endl;

        MoveBlock(x,y,n,i);

        blocked[n][i]=true;
    }

    n--;
    //cout<<endl<<endl;

    return;
}

///

void RemoveColumn()
{
    int i,j,in;
    int s;
    int x,y;

    //cout<<"Removing column "<<m<<endl;
    //cout<<endl;

    for (i=1;i<=n;i++)
    {
        ///Removing [i,m]
        x=-1;
        y=-1;

        for (j=1;j<=m;j++)
        {
            if (j!=m)
            s=1;
            else
            s=i;

            for (in=s;in<=n;in++)
            {
                if (in==curx && j==cury)
                continue;

                if (grid[in][j]==goal[i][m])
                {
                    x=in;
                    y=j;
                    break;
                }
            }

            if (x!=-1)
            break;
        }

        //cout<<"Trying to fill "<<i<<";"<<m<<" with the block at "<<x<<";"<<y<<endl;

        MoveBlock(x,y,i,m);

        blocked[i][m]=true;
    }

    m--;
    //cout<<endl<<endl;

    return;
}

///

int A[32];
int B[32];
int Len;

void S(int a,int b)
{
    int d=A[a];
    A[a]=A[b];
    A[b]=d;
    return;
}

bool Equal()
{
    int i;

    for (i=1;i<=Len;i++)
    {
        if (A[i]!=B[i])
        return false;
    }

    return true;
}

int main()
{
    //freopen("mytest.txt","r",stdin);
    //freopen("myans.txt","w",stdout);

    int i,j;
    int L,R;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            scanf("%d",&grid[i][j]);
            ctr1[ grid[i][j] ]++;
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            scanf("%d",&goal[i][j]);
            ctr2[ goal[i][j] ]++;
        }
    }

    for (i=1;i<=900;i++)
    {
        if (ctr1[i]!=ctr2[i])
        {
            printf("-1\n");
            return 0;
        }
    }

    for (i=0;i<=31;i++)
    {
        for (j=0;j<=31;j++)
        {
            blocked[i][j]=false;
            if (i<1 || i>n || j<1 || j>m)
            blocked[i][j]=true;
        }
    }

    begx=-1;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (grid[i][j]==goal[1][1])
            {
                begx=i;
                begy=j;
                break;
            }
        }
        if (begx!=-1)
        break;
    }

    curx=begx;
    cury=begy;

    if (n>=2 && m>=2)
    {
        //cout<<"Inititally at "<<curx<<";"<<cury<<endl;

        while(n>2)
        {
            RemoveLine();
        }

        while(m>2)
        {
            RemoveColumn();
        }
    }
    else
    {
        if (n==1)
        {
            Len=m;

            for (i=1;i<=m;i++)
            {
                A[i]=grid[1][i];
                B[i]=goal[1][i];
            }
        }
        else if (m==1)
        {
            Len=n;

            for (i=1;i<=n;i++)
            {
                A[i]=grid[i][1];
                B[i]=goal[i][1];
            }
        }

        L=-1;
        R=-1;

        for (i=1;i<=Len;i++)
        {
            for (j=i+1;j<=Len;j++)
            {
                S(j-1,j);
                if (Equal())
                {
                    L=i;
                    R=j;
                    break;
                }
            }

            if (L!=-1)
            break;

            for (j=Len;j>=i+1;j--)
            {
                S(j-1,j);
            }
        }

        if (L!=-1)
        {
            printf("%d\n",R-L);
            if (n==1)
            printf("%d %d\n",1,L);
            else
            printf("%d %d\n",L,1);

            for (i=L+1;i<=R;i++)
            {
                if (n==1)
                printf("%d %d\n",1,i);
                else
                printf("%d %d\n",i,1);
            }

            return 0;
        }

        ///

        for (i=1;i<=Len;i++)
        {
            for (j=i-1;j>=1;j--)
            {
                S(j,j+1);
                if (Equal())
                {
                    L=i;
                    R=j;
                    break;
                }
            }

            if (L!=-1)
            break;

            for (j=1;j<=i-1;j++)
            {
                S(j,j+1);
            }
        }

        if (L!=-1)
        {
            printf("%d\n",L-R);
            if (n==1)
            printf("%d %d\n",1,L);
            else
            printf("%d %d\n",L,1);

            for (i=L-1;i>=R;i--)
            {
                if (n==1)
                printf("%d %d\n",1,i);
                else
                printf("%d %d\n",i,1);
            }

            return 0;
        }

        ///

        printf("-1\n");
        return 0;
    }

    if (curx!=2 || cury!=2)
    {
        moves.push_back( make_pair(2,2) );
        SWAP(curx,cury,2,2);
    }

    if (grid[1][1]==goal[2][2])
    {
        if (grid[1][2]==goal[1][2]) ///everything is fine
        {
            moves.push_back( make_pair(1,1) );
        }
        else ///1;2 and 2;1 are swapped
        {
            moves.push_back( make_pair(1,2) );
            moves.push_back( make_pair(2,1) );
            moves.push_back( make_pair(2,2) );
            moves.push_back( make_pair(1,1) );
        }
    }
    else if (grid[1][2]==goal[2][2])
    {
        moves.push_back( make_pair(1,2) );

        if (grid[1][1]==goal[1][2])
        {
            moves.push_back( make_pair(1,1) );
        }
        else
        {
            moves.push_back( make_pair(2,1) );
            moves.push_back( make_pair(1,1) );
        }
    }
    else ///grid[2][1] == goal[2][2]
    {
        moves.push_back( make_pair(2,1) );

        if (grid[1][1]==goal[2][1])
        {
            moves.push_back( make_pair(1,1) );
        }
        else
        {
            moves.push_back( make_pair(1,2) );
            moves.push_back( make_pair(1,1) );
        }
    }

    printf("%d\n",moves.size());
    printf("%d %d\n",begx,begy);

    for (i=0;i<moves.size();i++)
    {
        printf("%d %d\n",moves[i].first,moves[i].second);
    }

    return 0;
}