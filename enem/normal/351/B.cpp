#include<bits/stdc++.h>

int main()
{
    int n;
    std::cin>>n;

    int p[n];
    for(int i=0;i<n;i++)
        std::cin>>p[i];

    int t=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(p[j]<p[i])
                t++;
    
    std::cout<<(((t>>1)<<2)|(t&1));
}