#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int x,y;
}p[8];
int a[10],b[10];
int cmp(node a,node b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main() {
    while(~scanf("%d%d",&p[0].x,&p[0].y)){
        a[0]=p[0].x,    b[0]=p[0].y;
        int cnt1=1,cnt2=1;
        for(int i=1;i<8;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
            int flag1=1,flag2=1;
            for(int j=0;j<cnt1;j++)
                if(p[i].x==a[j])
                    flag1=0;
            if(flag1)
                a[cnt1++]=p[i].x;
            for(int j=0;j<cnt2;j++)
                if(p[i].y==b[j])
                    flag2=0;
            if(flag2)
                b[cnt2++]=p[i].y;
        }
        if(cnt1!=3 || cnt2!=3){ 
            puts("ugly");
            continue;
        }
        sort(a,a+3);
        sort(b,b+3);
        if(a[0]==a[1] || a[1]==a[2] || b[0]==b[1] || b[1]==b[2]){   
            puts("ugly");
            continue;
        }
        sort(p,p+8,cmp);
        int flag=1,cnt=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){  
                if(i==1 && j==1)   
                    continue;
                if(a[i]==p[cnt].x && b[j]==p[cnt].y)
                    cnt++;
                else{
                    flag=0;
                    break;
                }
            }
        if(flag)
            puts("respectable");
        else
            puts("ugly");
    }
    return 0;
}