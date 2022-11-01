    #include<bits/stdc++.h>
        using namespace std;
        int main()
        {
            int x;
            cin>>x;
            while(x--)
            {
                int n,p;
                cin>>n>>p;
                long long ans=1,i=1;
                for(;i-1<=n;i<<=1)
                {
                    (ans*=(i>>1)+1)%=p;
                }
                (--(ans*=n-(i>>1)+2))%=p;
                if(ans<0)ans+=p;
                cout<<ans<<endl;
            }
        }