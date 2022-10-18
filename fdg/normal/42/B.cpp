#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int x1,x2,x3,x4,y1,y2,y3,y4;
    char a;
    cin >> a >> y1;
    x1=a-'a'+1;
    cin >> a >> y2;
    x2=a-'a'+1;
    cin >> a >> y3;
    x3=a-'a'+1;
    cin >> a >> y4;
    x4=a-'a'+1;
    int D[10][10]={0};
    int dx[]={1,1,1,0,0,-1,-1,-1},dy[]={-1,0,1,-1,1,-1,0,1};
    D[x3][y3]=1;
    for(int i=0;i<8;i++)
        D[x3+dx[i]][y3+dy[i]]=1;
    bool beat=false;
    for(int i=0;i<8;i++)
    {
        if (x4+dx[i]==x1&&y4+dy[i]==y1)
        {
            beat=true;
            break;
        }
    }
    for(int i=0;i<8;i++)
        if (x3+dx[i]==x1&&y3+dy[i]==y1) beat=false;
    if (y1==y2||x1==x2) beat=false;
    if (!beat)
    {
        D[x1][y1]=1;
        int cur=x1;
        while(cur>=1)
        {
            if (cur==x3&&y1==y3) break;
            D[cur][y1]=1;
            cur--;
        }
        cur=x1;
        while(cur<=8)
        {
            if (cur==x3&&y1==y3) break;
            D[cur][y1]=1;
            cur++;
        }
        cur=y1;
        while(cur>=1)
        {
            if (cur==y3&&x1==x3) break;
            D[x1][cur]=1;
            cur--;
        }
        cur=y1;
        while(cur<=8)
        {
            if (cur==y3&&x1==x3) break;
            D[x1][cur]=1;
            cur++;
        }
    }
    beat=false;
    for(int i=0;i<8;i++)
    {
        if (x4+dx[i]==x2&&y4+dy[i]==y2)
        {
            beat=true;
            break;
        }
    }
    for(int i=0;i<8;i++)
        if (x3+dx[i]==x2&&y3+dy[i]==y2) beat=false;
    if (y1==y2||x1==x2) beat=false;
    if (!beat)
    {
        D[x2][y2]=1;
        int cur=x2;
        while(cur>=1)
        {
            if (cur==x3&&y2==y3) break;
            D[cur][y2]=1;
            cur--;
        }
        cur=x2;
        while(cur<=8)
        {
            if (cur==x3&&y2==y3) break;
            D[cur][y2]=1;
            cur++;
        }
        cur=y2;
        while(cur>=1)
        {
            if (cur==y3&&x2==x3) break;
            D[x2][cur]=1;
            cur--;
        }
        cur=y2;
        while(cur<=8)
        {
            if (cur==y3&&x2==x3) break;
            D[x2][cur]=1;
            cur++;
        }
    }
    beat=true;
    if (D[x4][y4]!=1) beat=false;
    for(int i=0;i<8;i++)
        if (D[x4+dx[i]][y4+dy[i]]!=1&&x4+dx[i]>=1&&x4+dx[i]<=8&&y4+dy[i]>=1&&y4+dy[i]<=8) beat=false;
    if (beat) printf("CHECKMATE\n");
    else printf("OTHER\n");
    return 0;
}