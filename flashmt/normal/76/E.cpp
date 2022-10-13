#include<iostream>
#include<algorithm>
#include<cstdio>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int n;
long long sx,sy,sqx,sqy,re;

int main()
{
    int i,x,y;
    scanf("%d",&n);
    fr(i,1,n)
    {
        scanf("%d%d",&x,&y);     
        sx+=x; sy+=y;
        sqx+=x*x; sqy+=y*y;
    }
    re=(sqx+sqy)*n-sx*sx-sy*sy;
    cout << re << endl;
    //system("pause");
    return 0;
}