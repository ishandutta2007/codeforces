#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
#include <string>
#include <map>
#include <set>
#include <ctime>

using namespace std;

int cnt[10]={6,2,5,5,4,5,6,3,7,6};
char num[10][8]={"1011111",
                 "0000101",
                 "1110110",
                 "1110101",
                 "0101101",
                 "1111001",
                 "1111011",
                 "1000101",
                 "1111111",
                 "1111101"};

int sovp[10][10]={0};

char str[200002];

int pp()
{
    int len=strlen(str),num=0;
    for(int i=0;i<len;i++)
        num=10*num+str[i]-'0';
    int level=0,n=strlen(str)/2;
    for(int i=0;i<n;i++) level+=sovp[str[i]-'0'][str[i+n]-'0'];
    for(;;++num)
    {
        int k=num,l=0;
        char tmp[20]={0};
        while(k)
        {
            tmp[l++]=k%10+'0';
            k/=10;
        }
        int lev=0,nn=strlen(tmp)/2;
        for(int i=0;i<nn;i++) lev+=sovp[tmp[i]-'0'][tmp[i+nn]-'0'];
        if (lev>level) return num;
    }
}

bool solve()
{
    int level=0,n=strlen(str)/2;
    for(int i=0;i<n;i++) level+=sovp[str[i]-'0'][str[i+n]-'0'];
    int left=level,can=0;
    for(int i=2*n-1;i>=n;i--)
    {
        left-=sovp[str[i]-'0'][str[i-n]-'0'];
        for(int j=str[i]-'0'+1;j<10;j++)
            if (left+can+sovp[str[i-n]-'0'][j]>level)
            {
                str[i]=j+'0';
                left+=sovp[str[i-n]-'0'][j];
                for(i=i+1;i<2*n;i++)
                {
                    can-=cnt[str[i-n]-'0'];
                    for(int j=0;j<10;j++)
                        if (left+can+sovp[str[i-n]-'0'][j]>level)
                        {
                            str[i]=j+'0';
                            left+=sovp[str[i-n]-'0'][j];
                            break;
                        }
                }
                puts(str);
                return 1;
            }
        can+=cnt[str[i-n]-'0'];
    }
    for(int i=n-1;i>=0;i--)
    {
//      left-=sovp[str[i]-'0'][str[i-n]-'0'];
        can-=cnt[str[i]-'0'];
        for(int j=str[i]-'0'+1;j<10;j++)
            if (can+cnt[j]>level)
            {
                str[i]=j+'0';
                can+=cnt[j];
                for(i=i+1;i<n;i++)
                {
                    can-=7;
                    for(int j=0;j<10;j++)
                        if (can+cnt[j]>level)
                        {
                            str[i]=j+'0';
                            can+=cnt[j];
                            break;
                        }
                }
                left=0;
                for(i=n;i<2*n;i++)
                {
                    can-=cnt[str[i-n]-'0'];
                    for(int j=0;j<10;j++)
                        if (left+can+sovp[str[i-n]-'0'][j]>level)
                        {
                            str[i]=j+'0';
                            left+=sovp[str[i-n]-'0'][j];
                            break;
                        }
                }
                puts(str);
                return 1;
            }
        can+=7;
    }
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int t=0;t<7;t++)
                sovp[i][j]+=num[i][t]==num[j][t]&&num[i][t]=='1';
    gets(str);
    if (!solve()) cout << -1 << endl;
/*  for(int num=1000;num<10000;num++)
    {
        int k=num;
        for(int j=0;j<4;j++)
        {
            str[3-j]=k%10+'0';
            k/=10;
        }
        str[4]='\0';
        cout << num << endl;
//      cout << pp() << endl;
        if (!solve()) cout << -1 << endl;
        cout << endl;
    }*/
    return 0;
}