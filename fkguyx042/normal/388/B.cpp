#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
using namespace std;  
#define LL __int64  
#define maxn 50000001  
int maps[1001][1001];  
int biao[101];  
int lens;  
int nums;  
int st;  
void chu(int x)  
{  
    lens=0;  
    nums=0;  
    while(x)  
    {  
        if(x%3)  
        {  
            biao[lens]=x%3;  
            nums++;  
        }  
        else biao[lens]=0;  
        lens++;  
        x=x/3;  
    }  
}  
void dos()  
{  
    int i,j;  
    for(i=1;i<=st;i++)  
    {  
        for(j=1;j<=st;j++)  
        {  
            if(maps[i][j])maps[j][i]=1;  
        }  
    }  
}  
int main()  
{  
    int n,i,j,k;  
    int ans;  
    while(~scanf("%d",&n))  
    {  
        chu(n);//n3  
        st=3;  
        vector<int>vec;  
        for(i=0;i<lens;i++)  
        {  
            if(biao[i])//n30  
            {  
                int tt;  
                tt=0;  
                vec.clear();  
                if(biao[i]==1)  
                {  
                    maps[1][st]=1;  
                    vec.push_back(st);  
                    st++;  
                }  
                else  
                {  
                    maps[1][st]=1;  
                    vec.push_back(st);  
                    st++;  
                    maps[1][st]=1;  
                    vec.push_back(st);  
                    st++;  
                }  
                for(j=0;j<=i;j++)  
                {  
                    for(k=0;k<vec.size();k++)  
                    {  
                        maps[vec[k]][st]=1;  
                        maps[vec[k]][st+1]=1;  
                        maps[vec[k]][st+2]=1;  
                    }  
                    vec.clear();  
                    vec.push_back(st);  
                    vec.push_back(st+1);  
                    vec.push_back(st+2);  
                    st=st+3;  
                }  
                st=st-3;  
                for(k=1;k<=1000;k++)  
                {  
                    maps[k][st+1]=0;  
                    maps[k][st+2]=0;  
                }  
                for(;j<lens;j++)  
                {  
                    maps[st][st+1]=1;  
                    st++;  
                }  
                maps[st][2]=1;  
                st++;  
            }  
        }  
        st--;  
        dos();  
        cout<<st<<endl;  
        for(i=1;i<=st;i++)  
        {  
            for(j=1;j<=st;j++)  
            {  
                if(maps[i][j])cout<<"Y";  
                else cout<<"N";  
            }  
            cout<<endl;  
        }  
    }  
    return 0;  
}