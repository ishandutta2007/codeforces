    #include<iostream>
    using namespace std;
    int a[100010];
    int main()
    {
        int n,m;
        cin>>n>>m;
        long long sum=0;
        for(int i=1;i<=m;++i)
        {
            cin>>a[i];
            if(a[i]>n-i+1){puts("-1");return 0;}
            sum+=a[i];
        }
        if(sum<n){puts("-1");return 0;}
        for(int i=1,l=0;i<=m;++i)
        {
            l=max(n+1-sum,l+1ll);
            cout<<l<<' ';
            sum-=a[i];
        }
        return 0;
    }