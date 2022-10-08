#include <iostream>
using namespace std;

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    long long w,h;
    long long total=0,i,j;
    long long pts1,pts2;
    
    cin>>w>>h;
    h++;
    w++;
    for (i=1;i<=h;i++)
    {
        for (j=1;j<=w;j++)
        {
            pts1=MIN(h-i,i-1);
            pts2=MIN(w-j,j-1);
            total=total+pts1*pts2;
        }
    }
    
    cout<<total<<endl;
    return 0;
}