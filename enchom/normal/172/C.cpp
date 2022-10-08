#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

struct student
{
    Int t,x,orgind;
};

student students[100001];
student going[100001];
Int answers[100001];

bool SortEm(student a,student b)
{
    return (a.x<b.x);
}

int main()
{
    Int n,m;
    Int i,j;
    Int uk=1;
    Int thetime=0;
    Int filled=0;
    Int laststop;
    Int firstkid,lastkid;
    Int thisstopkids;
    
    cin>>n>>m;
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&students[i].t,&students[i].x);
        students[i].orgind=i;
    }
    firstkid=-1;
    while (uk<=n)
    {
        filled++;
        going[filled]=students[uk];
        lastkid=uk;
        if (firstkid==-1)
        firstkid=uk;
        
        if (thetime<students[uk].t)
        thetime=students[uk].t;
        
        if (filled==m || uk==n)
        {
            laststop=0;
            thisstopkids=0;
            sort(going+1,going+1+filled,SortEm);
            for (i=1;i<=filled;i++)
            {
                if (going[i].x==laststop)
                {
                    answers[ going[i].orgind ]=thetime;
                    
                    thisstopkids++;
                }
                else
                {
                    if (thisstopkids!=0)
                    thetime=thetime+(1+thisstopkids/2);
                    
                    thetime=thetime+going[i].x-laststop;
                    
                    answers[ going[i].orgind ]=thetime;
                                        
                    thisstopkids=1;
                    laststop=going[i].x;
                }
            }
            thetime=thetime+(thisstopkids/2+1);
            thetime=thetime+laststop;
            filled=0;
            firstkid=-1;
        }
        uk++;
    }
    for (i=1;i<=n;i++)
    {
        cout<<answers[i];
        if (i==n)
        cout<<endl;
        else
        cout<<" ";
    }
    return 0;
}