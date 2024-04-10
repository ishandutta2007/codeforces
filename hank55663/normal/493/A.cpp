#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct member{
    int number,time;
    char team[30];
};
bool operator <(const member &a,const member &b)
{
    return a.time<b.time;
}
member aname[200];
main()
{
    char name[2][30];
    scanf("%s\n%s",name[0],name[1]);
    int n,player[2][100][2];
    scanf("%d",&n);
    for(int i=0;i<2;i++)
    for(int j=0;j<100;j++)
    {
        player[i][j][0]=0;
        player[i][j][1]=0;
    }
    for(int i=0;i<n;i++)
    {
        char a,b;
        int x,y;
        scanf("%d %c %d %c",&y,&a,&x,&b);
        if(a=='h')
        {
            if(b=='r')
            {
                if(player[0][x][0]<2){
                player[0][x][0]=2;
                player[0][x][1]=y;
                }
            }
            if(b=='y')
            {
                if(player[0][x][0]<2){
                player[0][x][0]++;
                player[0][x][1]=y;
                } 
            }
        }
        else
        {
            if(b=='r')
            {
                if(player[1][x][0]<2){
                player[1][x][0]=2;
                player[1][x][1]=y;
                }
            }
            if(b=='y')
            {
                if(player[1][x][0]<2){
                player[1][x][0]++;
                player[1][x][1]=y;
                } 
            }
        }
    }
    int l=0;
    for(int i=0;i<2;i++)
    for(int j=0;j<100;j++)
    {
        if(player[i][j][0]>=2)
        {
            aname[l].time=player[i][j][1];
            for(int k=0;k<strlen(name[i]);k++)
            aname[l].team[k]=name[i][k];
            aname[l].number=j;
            l++;
        }
    }
    sort(aname,aname+l);
    for(int i=0;i<l;i++)
    {
        printf("%s %d %d\n",aname[i].team,aname[i].number,aname[i].time);
    }
    return 0;
}