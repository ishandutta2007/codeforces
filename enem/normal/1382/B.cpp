#include<iostream>

bool firstWins(int a[],int n)
{
    if(n==0)
        return false;

    bool nextFirstWins = firstWins(a+1,n-1);

    //does not depends on on nextFirstWins
    if(a[0]>1)
        return true;

    else
        return !nextFirstWins;
}

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
            std::cin>>a[i];

        if(firstWins(a,n))
            std::cout<<"First\n";
        else
            std::cout<<"Second\n";
    }

    return 0;
}