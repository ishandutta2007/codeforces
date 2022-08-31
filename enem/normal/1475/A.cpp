#include<bits/stdc++.h>

int main(){
    int tc;std::cin>>tc;
    while(tc--)
    {
        long long n;std::cin>>n;
        if(__builtin_popcountll(n)==1) std::cout<<"NO\n";
        else std::cout<<"YES\n";
    }
}