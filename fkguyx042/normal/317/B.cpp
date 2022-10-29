#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
#include<queue>  
using namespace std;  
#define N 180  
int inq[N][N],ans[N][N];//inqqueue,ans  
int n,t,x,y;  
int dx[]={-1,0,1,0};  
int dy[]={0,1,0,-1};  
bool is_ok(int x,int y)  
{  
    if(x>=0&&y>=0&&x<180&&y<180) return 1;  
    return 0;  
}  
struct node  
{  
    int x,y;  
};//,,ans  
void bfs()  
{  
    queue<node>q;  
    node vn,vw;  
    vn.x=90;  
    vn.y=90;  
    inq[vn.x][vn.y]=1;  
    ans[vn.x][vn.y]=n;  
    if(ans[vn.x][vn.y]>=4)//>=4,,  
    q.push(vn);  
    while(!q.empty())  
    {  
        vn=q.front();  
        q.pop();  
        inq[vn.x][vn.y]=0;  
        int p=ans[vn.x][vn.y]/4;  
        ans[vn.x][vn.y]-=4*p;//-4,WA,<=ans4  
        for(int i=0;i<4;i++)  
        {  
            int a=vn.x+dx[i];  
            int b=vn.y+dy[i];  
            if(is_ok(a,b))  
            {  
                ans[a][b]+=p;  
                if(ans[a][b]>=4&&inq[a][b]==0)//inq[a][b]==0,,MLE,SPFA  
                {  
                    vw.x=a;  
                    vw.y=b;  
                    inq[a][b]=1;  
                    q.push(vw);  
                }  
            }  
        }  
    }  
}  
int main()  
{  
    while(~scanf("%d%d",&n,&t))  
    {  
        memset(inq,0,sizeof(inq));  
        memset(ans,0,sizeof(ans));  
        bfs();  
        while(t--)  
        {  
            scanf("%d%d",&x,&y);  
            x+=90;  
            y+=90;  
            if(x<0||x>=180||y<0||y>=180)  
            printf("0\n");  
            else  
            {  
                printf("%d\n",ans[x][y]);  
            }  
        }  
    }  
}