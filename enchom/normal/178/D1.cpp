#include <iostream>
using namespace std;

struct pairs
{
    int a,b,c,d;
};

pairs pr[100000];

int main()
{
    int n;
    int arr[17];
    int i,j,in,ja,i2,j2,i3,j3,i4,j4;
    int pL=0;
    int ans=0;
    bool TFO[17];
    for (i=1;i<=16;i++)
    TFO[i]=false;
    
    cin>>n;
    
    for (i=1;i<=n*n;i++)
    {
        cin>>arr[i];
        ans=ans+arr[i];
    }
    ans=ans/n;
    
    if (n==1)
    {
        cout<<arr[1]<<endl<<arr[1]<<endl;
        return 0;
    }
    
    if (n==2)
    {
        cout<<ans<<endl;
        cout<<arr[1]<<" "<<arr[2]<<endl;
        cout<<arr[3]<<" "<<arr[4]<<endl;
        return 0;
    }
    
    if (n==3)
    {
        for (i=1;i<=9;i++)
        {
            TFO[i]=true;
            for (j=1;j<=9;j++)
            {
                if (TFO[j])
                continue;
                
                TFO[j]=true;
                for (in=1;in<=9;in++)
                {
                    if (TFO[in])
                    continue;
                    
                    TFO[in]=true;
                    if (arr[i]+arr[j]+arr[in]==ans)
                    {
                        for (ja=1;ja<=9;ja++)
                        {
                            if (TFO[ja])
                            continue;
                            
                            TFO[ja]=true;
                            for (i2=1;i2<=9;i2++)
                            {
                                if (TFO[i2])
                                continue;
                                
                                TFO[i2]=true;
                                if (arr[ja]+arr[i2]+arr[j]==ans)
                                {
                                    for (j2=1;j2<=9;j2++)
                                    {
                                        if (TFO[j2])
                                        continue;
                                        
                                        TFO[j2]=true;
                                        if (arr[j2]+arr[i2]+arr[in]==ans)
                                        {
                                            for (i3=1;i3<=9;i3++)
                                            {
                                                if (TFO[i3])
                                                continue;
                                            
                                                TFO[i3]=true;
                                                if (arr[i]+arr[ja]+arr[i3]==ans && arr[i3]+arr[j]+arr[j2]==ans)
                                                {
                                                    for (j3=1;j3<=9;j3++)
                                                    {
                                                        if (TFO[j3])
                                                        continue;
                                                        
                                                        TFO[j3]=true;
                                                        if (arr[i]+arr[j3]+arr[i2]==ans)
                                                        {
                                                            for (i4=1;i4<=9;i4++)
                                                            {
                                                                if (TFO[i4])
                                                                continue;
                                                                
                                                                TFO[i4]=true;
                                                                if (arr[ja]+arr[i4]+arr[in]==ans && arr[i4]+arr[j]+arr[j3]==ans)
                                                                {
                                                                    cout<<ans<<endl;
                                                                    cout<<arr[i]<<" "<<arr[j3]<<" "<<arr[i2]<<endl;
                                                                    cout<<arr[i3]<<" "<<arr[j]<<" "<<arr[j2]<<endl;
                                                                    cout<<arr[ja]<<" "<<arr[i4]<<" "<<arr[in]<<endl;
                                                                    return 0;
                                                                }
                                                                TFO[i4]=false;
                                                            }
                                                        }
                                                        TFO[j3]=false;
                                                    }
                                                }
                                                TFO[i3]=false;
                                            }
                                        }
                                        TFO[j2]=false;
                                    }
                                }
                                TFO[i2]=false;
                            }
                            TFO[ja]=false;
                        }
                    }
                    TFO[in]=false;
                }
                TFO[j]=false;
            }
            TFO[i]=false;
        }
    }
    
}