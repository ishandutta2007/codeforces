#include<cstdio>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    int l=1,r=n;
    while(r-l>=3)
    {
        int mid=(l+r)/2,x,y;
        printf("? %d\n",mid);
        fflush(stdout);
        scanf("%d",&x);
        printf("? %d\n",mid+1);
        fflush(stdout);
        scanf("%d",&y);
        if(x<y) r=mid+1;
        else l=mid;
    }
    if(r-l==2)
    {
        int x,y,z;
        printf("? %d\n",l);
        fflush(stdout);
        scanf("%d",&x);
        printf("? %d\n",l+1);
        fflush(stdout);
        scanf("%d",&y);
        printf("? %d\n",r);
        fflush(stdout);
        scanf("%d",&z);
        if(x<y && x<z) printf("! %d\n",l); 
        if(y<x && y<z) printf("! %d\n",l+1); 
        if(z<y && z<x) printf("! %d\n",r); 
    }
    if(r-l==1)
    {
        int x,y;
        printf("? %d\n",l);
        fflush(stdout);
        scanf("%d",&x);
        printf("? %d\n",r);
        fflush(stdout);
        scanf("%d",&y);
        if(x<y) printf("! %d\n",l);
        else printf("! %d\n",r);
    }
    if(r-l==0)
    {
        printf("! %d\n",l);
    }
}