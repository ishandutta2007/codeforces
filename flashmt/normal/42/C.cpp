#include<iostream>
using namespace std;
int a[4],i,mx,x;
bool kt;
int main()
{
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    while (a[0]!=1 || a[1]!=1 || a[2]!=1 || a[3]!=1)
    {
          kt=false; mx=0; x=0;
//          cout <<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<< endl; system("pause");
          for (i=0;i<=3;i++)
             if (a[i]%2==0 && a[(i+1)%4]%2==0) 
             {
                if (a[i]+a[(i+1)%4]>mx)
                {
                   mx=a[i]+a[(i+1)%4]; x=i;
                }
                kt=true; 
             }
          if (kt) 
          {
             cout << "/" << (x+1) << endl;
             a[x]/=2; a[(x+1)%4]/=2;     
             continue;
          }
          for (i=0;i<=3;i++)
             if (a[i]%2==1 && a[(i+1)%4]%2==1) 
             {
                if (a[i]+a[(i+1)%4]>mx)
                {
                   mx=a[i]+a[(i+1)%4]; x=i;
                }
                kt=true; 
             }
          if (!kt || mx==2)
            for (i=0;i<=3;i++)
               if (a[i]+a[(i+1)%4]>mx)
                {
                   mx=a[i]+a[(i+1)%4]; x=i;
                }
          cout << "+" << (x+1) << endl;
          a[x]++; a[(x+1)%4]++;
    }    
//    system("pause");
    return 0;
}