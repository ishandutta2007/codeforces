#include <bits/stdc++.h> 
using namespace std; 
  
/* This function merges two sorted arrays and returns inversion 
   count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    int inv_count = 0; 
  
    int i = left; /* i is index for left subarray*/
    int j = mid;  /* i is index for right subarray*/
    int k = left; /* i is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) 
    { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
  
            /* this is tricky -- see above explanation/ 
              diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray 
     (if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray 
     (if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
  
/* An auxiliary recursive function that sorts the input 
   array and returns the number of inversions in the 
   array. */
int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) 
    { 
        /* Divide the array into two parts and call 
          _mergeSortAndCountInv() for each of the parts */
        mid = (right + left)/2; 
  
        /* Inversion count will be sum of inversions in 
           left-part, right-part and number of inversions 
           in merging */
        inv_count  = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid+1, right); 
  
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid+1, right); 
    } 
  
    return inv_count; 
} 
  
/* This function sorts the input array and returns the 
   number of inversions in the array */
int countSwaps(int arr[], int n) 
{ 
    int temp[n]; 
    return _mergeSort(arr, temp, 0, n - 1); 
} 

int main() {
    int q; cin>>q; while(q--) {
        int n; string a, b; cin>>n>>a>>b;
        int x[n], y[n]; for(int i=0; i<n; i++) {x[i]=a[i]-'a'; y[i]=b[i]-'a';}
        sort(a.begin(), a.end());sort(b.begin(), b.end());
        bool c=0, chk=0;
        for(int i=0; i<n; i++) if(a[i]==a[i+1]||b[i]==b[i+1]) chk=1;
        if(a==b&&(chk||(countSwaps(x, n)-countSwaps(y, n))%2==0)) c=1;
        if(c==1) cout<<"YES\n"; else cout<<"NO\n";
    }
}