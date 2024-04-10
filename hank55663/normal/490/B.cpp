#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
main()
{
    map <int ,int >m;
    map <int ,int >m2;
    int n;
    scanf("%d",&n);
    int i,a[200001][2],b,head2,head;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
        m[a[i][0]]=a[i][1];
        m2[a[i][1]]=a[i][0];
        if(a[i][0]==0)
            b=a[i][1];
    }
    head2=m[0];
    for(i=0;i<n;i++)
        if(m2[a[i][0]]==0&&a[i][0]!=b)
            {
                head=a[i][0];
            }
 printf("%d %d ",head,head2);
 for(i=0;i<n-2;i++)
    {
        if(i%2==0)
        {head=m[head];
        printf("%d ",head);
        }
        else
        {

        head2=m[head2];
        printf("%d ",head2);
        }
    }
 return 0;
}