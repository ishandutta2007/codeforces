#include<cstdio>
int main()
{
int n;
scanf("%d",&n);
puts(n<1500 ? "1" :(n<3500 ? "2" : "3"));
return 0;
}