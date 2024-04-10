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
    int i,j,in,ja,i2,j2,i3,j3,i4,j4,i5,j5,i6,j6,i7,j7,i8,j8;
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
    
    
    if (n==4)
    {
        for (i=1;i<=16;i++)
        {
            TFO[i]=true;
            for (j=1;j<=16;j++)
            {
                if (TFO[j])
                continue;
                
                TFO[j]=true;
                for (in=1;in<=16;in++)
                {
                    if (TFO[in])
                    continue;
                    
                    TFO[in]=true;
                    for (ja=1;ja<=16;ja++)
                    {
                        if (TFO[ja])
                        continue;
                        
                        TFO[ja]=true;
                        if (arr[i]+arr[j]+arr[ja]+arr[in]==ans)
                        {
                            for (i2=1;i2<=16;i2++)
                            {
                                if (TFO[i2])
                                continue;
                                
                                TFO[i2]=true;
                                for (j2=1;j2<=16;j2++)
                                {
                                    if (TFO[j2])
                                    continue;
                                    
                                    TFO[j2]=true;
                                    for (i3=1;i3<=16;i3++)
                                    {
                                        if (TFO[i3])
                                        continue;
                                        
                                        TFO[i3]=true;
                                        if (arr[i]+arr[i2]+arr[i3]+arr[j2]==ans)
                                        {
                                            for (j3=1;j3<=16;j3++)
                                            {
                                                if (TFO[j3])
                                                continue;
                                                
                                                TFO[j3]=true;
                                                for (i4=1;i4<=16;i4++)
                                                {
                                                    if (TFO[i4])
                                                    continue;
                                                    
                                                    TFO[i4]=true;
                                                    if (arr[i3]+arr[j3]+arr[i4]+arr[ja]==ans)
                                                    {
                                                        for (j4=1;j4<=16;j4++)
                                                        {
                                                            if (TFO[j4])
                                                            continue;
                                                            
                                                            TFO[j4]=true;
                                                            for (i5=1;i5<=16;i5++)
                                                            {
                                                                if (TFO[i5])
                                                                continue;
                                                                
                                                                TFO[i5]=true;
                                                                if (arr[i5]+arr[j]+arr[j4]+arr[j3]==ans)
                                                                {
                                                                    for (j5=1;j5<=16;j5++)
                                                                    {
                                                                        if (TFO[j5])
                                                                        continue;
                                                                        
                                                                        TFO[j5]=true;
                                                                        if (arr[j5]+arr[j2]+arr[j4]+arr[in]==ans)
                                                                        {
                                                                            for (i6=1;i6<=16;i6++)
                                                                            {
                                                                                if (TFO[i6])
                                                                                continue;
                                                                                
                                                                                TFO[i6]=true;
                                                                                for (j6=1;j6<=16;j6++)
                                                                                {
                                                                                    if (TFO[j6])
                                                                                    continue;
                                                                                    
                                                                                    TFO[j6]=true;
                                                                                    if (arr[j6]+arr[i6]+arr[in]+arr[i4]==ans)
                                                                                    {
                                                                                        for (i7=1;i7<=16;i7++)
                                                                                        {
                                                                                            if (TFO[i7])
                                                                                            continue;
                                                                                            
                                                                                            TFO[i7]=true;
                                                                                            if (arr[i7]+arr[i6]+arr[j]+arr[i2]==ans)
                                                                                            {
                                                                                                for (j7=1;j7<=16;j7++)
                                                                                                {
                                                                                                    if (TFO[j7])
                                                                                                    continue;
                                                                                                    
                                                                                                    TFO[j7]=true;
                                                                                                    if (arr[j7]+arr[j6]+arr[i5]+arr[i]==ans && arr[j7]+arr[i7]+arr[j5]+arr[ja]==ans && arr[j7]+arr[i6]+arr[j4]+arr[i3]==ans)
                                                                                                    {
                                                                                                        cout<<ans<<endl;
                                                                                                        cout<<arr[i]<<" "<<arr[i2]<<" "<<arr[j2]<<" "<<arr[i3]<<endl;
                                                                                                        cout<<arr[i5]<<" "<<arr[j]<<" "<<arr[j4]<<" "<<arr[j3]<<endl;
                                                                                                        cout<<arr[j6]<<" "<<arr[i6]<<" "<<arr[in]<<" "<<arr[i4]<<endl;
                                                                                                        cout<<arr[j7]<<" "<<arr[i7]<<" "<<arr[j5]<<" "<<arr[ja]<<endl;
                                                                                                        return 0;
                                                                                                    }
                                                                                                    TFO[j7]=false;
                                                                                                }
                                                                                            }
                                                                                            TFO[i7]=false;
                                                                                        }
                                                                                    }
                                                                                    TFO[j6]=false;
                                                                                }
                                                                                TFO[i6]=false;
                                                                            }
                                                                        }
                                                                        TFO[j5]=false;
                                                                    }
                                                                }
                                                                TFO[i5]=false;
                                                            }
                                                            TFO[j4]=false;
                                                        }
                                                    }
                                                    TFO[i4]=false;
                                                }
                                                TFO[j3]=false;
                                            }
                                        }
                                        TFO[i3]=false;
                                    }
                                    TFO[j2]=false;
                                }
                                TFO[i2]=false;
                            }
                        }
                        TFO[ja]=false;
                    }
                    TFO[in]=false;
                }
                TFO[j]=false;
            }
            TFO[i]=false;
        }
    }
}