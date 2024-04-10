#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define eps 1e-8
using namespace std;

const int maxn = 100007 , maxnum = 1000000000;

struct Node
{
    int mark , K1 , K2;
    double x,y;
}pt[maxn] , a[maxn] , A , B;

int Y_sort[maxn] , n;
double Tmax;

double MinN(double a,double b)
{
    if(a<b) return a;
    else return b;
}
inline double Distance(Node &a,Node &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
 int CMP_X(const void *a,const void *b)
{
    if(((Node*)a)->x<((Node*)b)->x) return -1;
    else return 1;
}
int CMP_Y(const void *a,const void *b)
{
    if(pt[(*(int*)a)].y<pt[(*(int*)b)].y) return -1;
    else return 1;
}

void update( Node a , Node b )
{
    if ( Distance(a,b)+eps < Tmax )
    {
        Tmax = Distance(a,b);
        A = a , B = b;
    }
}

double Nearest_Point_Distance(int first,int end)
{
    if(end-first==1) 
    {
        update(pt[first],pt[first+1]);
        return Distance(pt[first],pt[first+1]);
    }
    else 
    if(end-first==2) 
    {
        update(pt[first],pt[first+1]);
        update(pt[first+1],pt[first+2]);
        update(pt[first],pt[first+2]);
        return MinN(MinN(Distance(pt[first],pt[first+1]),Distance(pt[first+1],pt[first+2])),Distance(pt[first],pt[first+2]));  
    }
    int mid=(first+end)/2;
    double min_dist=MinN(Nearest_Point_Distance(first,mid),Nearest_Point_Distance(mid+1,end)); 
    int Y_end=0;
    for(int i=mid;i>=first&&(pt[mid].x-pt[i].x)<min_dist;i--)
    {
        Y_sort[Y_end++]=i;
    }
    for(int i=mid+1;i<=end&&(pt[i].x-pt[mid+1].x)<min_dist;i++)
    {
        Y_sort[Y_end++]=i;
    }
    qsort(Y_sort,Y_end,sizeof(Y_sort[0]),CMP_Y);
    for(int i=0;i<Y_end;i++)
    {
        for(int j=i+1;j<Y_end&&pt[Y_sort[j]].y-pt[Y_sort[i]].y<min_dist;j++)
        {
            update(pt[Y_sort[i]],pt[Y_sort[j]]);
            min_dist=MinN(min_dist,Distance(pt[Y_sort[i]],pt[Y_sort[j]]));  
        }
    }
    return min_dist;
}

void work()
{
    scanf( "%d" , &n );
    for ( int i = 0 ; i < n ; i++ ) scanf( "%lf %lf" , &a[i].x , &a[i].y );
    for ( int i = 0 ; i < n ; i++ ) 
    {
        pt[i].x = fabs(a[i].x) , pt[i].y = fabs(a[i].y) , pt[i].mark = i;
        if ( a[i].x > -eps && a[i].y > -eps ) pt[i].K1 = 1 , pt[i].K2 = 4;
        if ( a[i].x < eps && a[i].y > -eps ) pt[i].K1 = 2 , pt[i].K2 = 3;
        if ( a[i].x > -eps && a[i].y < eps ) pt[i].K1 = 3 , pt[i].K2 = 2;
        if ( a[i].x < -eps && a[i].y < -eps ) pt[i].K1 = 4 , pt[i].K2 = 1;
    }
    qsort(pt,n,sizeof(pt[0]),CMP_X);
    Tmax = maxnum;
    Nearest_Point_Distance(0,n-1);
    printf( "%d %d %d %d\n" , A.mark+1 , A.K1 , B.mark+1 , B.K2 );
}

int main()
{
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    work();
    return 0;
}