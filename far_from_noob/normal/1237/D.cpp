#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
int getMid(int s, int e)  
{ 
    return s + (e - s) / 2; 
}int MaxUtil(int* st, int ss, int se, int l,  
            int r, int node) 
{ 
    if (l <= ss && r >= se) 
        return st[node]; 
    if (se < l || ss > r) 
        return -1; 
    int mid = getMid(ss, se); 
      
    return max(MaxUtil(st, ss, mid, l, r,  
                       2 * node + 1), 
               MaxUtil(st, mid + 1, se, l,  
                       r, 2 * node + 2)); 
}
void updateValue(int arr[], int* st, int ss, int se,  
                 int index, int value, int node) 
{ 
    if (index < ss || index > se)  
    { 
        cout << "Invalid Input" << endl; 
        return; 
    } 
      
    if (ss == se)  
    {    
        // update value in array and in segment tree 
        arr[index] = value; 
        st[node] = value; 
    } 
    else { 
            int mid = getMid(ss, se); 
              
            if (index >= ss && index <= mid) 
                updateValue(arr, st, ss, mid, index,  
                            value, 2 * node + 1); 
            else
                updateValue(arr, st, mid + 1, se,  
                            index, value, 2 * node + 2); 
              
            st[node] = max(st[2 * node + 1],  
                       st[2 * node + 2]); 
    } 
    return; 
} 

int getMax(int* st, int n, int l, int r) 
{ 
    // Check for erroneous input values 
    if (l < 0 || r > n - 1 || l > r)  
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return MaxUtil(st, 0, n - 1, l, r, 0); 
} 
int constructSTUtil(int arr[], int ss, int se,  
                    int* st, int si) 
{ 
    if (ss == se)  
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
    int mid = getMid(ss, se); 
      
    st[si] = max(constructSTUtil(arr, ss, mid, st,  
                                 si * 2 + 1), 
                 constructSTUtil(arr, mid + 1, se,  
                                 st, si * 2 + 2)); 
      
    return st[si]; 
} 
int* constructST(int arr[], int n) 
{ 
    // Height of segment tree 
    int x = (int)(ceil(log2(n))); 
  
    // Maximum size of segment tree 
    int max_size = 2 * (int)pow(2, x) - 1; 
  
    // Allocate memory 
    int* st = new int[max_size]; 
  
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n - 1, st, 0); 
  
    // Return the constructed segment tree 
    return st; 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        int a[n];
        int b[2*n];
        ll ans[n];
        ll index,maxi=0;
        ll mini;
        fo(i,n){
            cin>>a[i];
            b[i]=a[i],b[n+i]=a[i];
            if(a[i]>maxi)maxi=a[i],index=i;
        }
        int *st = constructST(b, 2*n); 
        //cout<<getMax(st, 2*n, 1 , 4)<<endl;
        ll j=index+1;
        ll temp=a[index];
        for(int i=index ;i <= n+index-1;i++){
            if(a[i%n]*2< a[index]){j=i,ans[index]=i-index;break;mini=a[i%n];}
            if(i==n+index-1)j=-1;
        }
        if(j==-1){
            fo(i,n)cout<<-1<< " ";
            return 0;
        }
        for(int i=index+1;i< n+index;i++){
            if(j==index+n){
                ans[i%n]=index+n-i+ans[index];
                continue;
            }
            ll maxim=getMax(st,2*n,i,j);
            if(maxim>2*a[j%n])ans[i%n]=j-i;
            else {
                //ll maxim=getMax(st,2*n,i,j);
            while(j<n+index){
                if(a[j%n]*2 < maxim){ans[i%n]=j-i;break;}
                else maxim=max(maxim,(ll)a[j%n]),j++;
                //cout<<i<<j<<endl;
            }
            }
            if(j==index+n){
                ans[i%n]=index+n-i+ans[index];
                
            }
            
        }
        fo(i,n)cout<<ans[i]<< " ";
        
    }

    return 0;
}