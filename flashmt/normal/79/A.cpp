#include<iostream>
using namespace std;
const int a[]={2,1,0};
      int b[]={2,12,22};
int x,y,z=0,kt;

int main()
{
    cin >> x >> y;
    kt=1;
    while (kt)
    {
       kt=0;   
       if (!z)
       {
          for (int i=0;i<3;i++)
            if (x>=a[i] && y>=b[i])
            {
               x-=a[i]; y-=b[i]; kt=1; break;         
            }    
          if (!kt) cout << "Hanako" << endl;
       }
       else
       {
          for (int i=2;i>=0;i--)
            if (x>=a[i] && y>=b[i])
            {
               x-=a[i]; y-=b[i]; kt=1; break;
            } 
          if (!kt) cout << "Ciel" << endl;
       }
       z^=1;     
    }
    //system("pause");
    return 0;
}