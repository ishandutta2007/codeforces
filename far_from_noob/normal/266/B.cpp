#include <iostream>
using namespace std;

int main() {
    int n,t;
	cin >> n >> t;
	char string[n],temp;
	for(int i=0;i<n;i++)
	{
	    cin >> string[i];
	}
	for(int j=0;j<t;j++){
	    for(int i=0;i<n-1;i++)
	    {
	        if(string[i]=='B' && string[i+1]=='G'){
	            temp=string[i];
	            string[i]=string[i+1];
	            string[i+1]=temp;
	            i++;
	        }
	    }
	}
	for(int i=0;i<n;i++)
	{
	    cout << string[i];
	}
	return 0;
}