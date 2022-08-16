#include<bits/stdc++.h>

int main()
{
				int t;
				std::cin>>t;
				while(t--)
				{
								int n;
								std::cin>>n;
								int a[n];
								for(int i=0;i<n;i++)
								{
												std::cin>>a[i];
								}
								int l=n,r=n;
								for(int i=0;i<n;i++)
								{
												if(a[i]<i)
												{
																l=i;
																break;
												}
								}
								for(int i=0;i<n;i++)
								{
												if(a[n-1-i]<i)
												{
																r=i;
																break;
												}
								}
								if(l+r<n)
								{
												std::cout<<"No\n";
								}
								else if(l+r>n)
								{
												std::cout<<"Yes\n";
								}
								else
								{
												if(l!=n/2||n%2==1) 
												    std::cout<<"Yes\n";
												else if(a[l-1]==l-1&&a[l]==l-1)
												    std::cout<<"No\n";
												else
												    std::cout<<"Yes\n";
								}
				}
				return 0;
}