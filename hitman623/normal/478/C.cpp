#include <iostream>

using namespace std;

int main()
{
   long long  ar[3],i,j,t,p=0;
   cin>>ar[0]>>ar[1]>>ar[2];
   for(i=0;i<3;++i)
    for(j=i+1;j<3;++j)
   {
       if(ar[i]>ar[j])
       {
           t=ar[i];
           ar[i]=ar[j];
           ar[j]=t;
       }
   }
   long long  a=ar[0],b=ar[1],c=ar[2],x,y;
  if(c>1 && b>0)
  {if(c/2<=a+b )
  {
     x=(4*a-2*b+c)/6;
     y=(c+b-2*a)/3;

     if(x==0 && y==0) x++;
if(x+y<c/2) y++;
else if (x+y>c/2) y--;
     a-=x;
     b-=y;
     p+=c/2;
     c%=2;
   }
   else {c-=2*(a+b);p+=a+b;a=0;b=0;}
   }if(b>=2*a) {p+=a;b-=2*a;a=0;}
   else {p+=b/2;a-=b/2;   b%=2;}
 if(a>=2)a=2;
 if(b>=2)b=2;
   if(c==1 || b==1)
   {if(a==2) ++p;
    else p+=(a+b+c)/3;}
    cout<<p;
    return 0;
}