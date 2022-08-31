#include<bits/stdc++.h>

int main()
{
				int t;
				std::cin>>t;
				while(t--)
				{
								int n;
								std::cin>>n;
								std::string s;
								std::cin>>s;
								std::vector<int> v;
								for(int i=0;i<n;i++)
								{
												if((s[i]-'0')&1)
												{
																v.push_back(s[i]-'0');
												}
								}
								if(v.size()>=2)
								    std::cout<<v[0]<<v[1]<<'\n';
								else
								    std::cout<<-1<<'\n';
				}
				return 0;
}