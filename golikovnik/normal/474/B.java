import java.util.Scanner;
import java.io.*;

public class BinarySearch {
	static int arr[][];
	
		public static int binarySearch(int left, int right, int wanted, int arr[]){
			int mid = left + (right - left)/2;
			while(left + 1 < right){
				mid = left + (right - left)/2;
				if(arr[mid] == wanted){
					break;
				}else if(arr[mid] > wanted){
					right = mid;
				}else{
					left = mid;
				}
			}
			return mid;
		}
		public static int binarySearchWorms(int left, int right, int wanted){
			int mid = left + (right - left)/2;
			while(left + 1 < right){
				mid = left + (right - left)/2;
				if(arr[mid][0] <= wanted && arr[mid][1] >= wanted){
					break;
				}else if(arr[mid][0] > wanted){
					right = mid;
				}else{
					left = mid;
				}
			}
			return mid;
		}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		arr = new int[n][2];
		arr[0][0] = 0;
		arr[0][1] = in.nextInt() - 1;
		for(int i = 1; i < n; i++){
			arr[i][0] = arr[i-1][1] + 1;
			arr[i][1] = arr[i][0] + in.nextInt() - 1;
		}
		
		int number = in.nextInt();
		int worm = 0;
		for(int i = 0; i < number; i++){
			worm = in.nextInt() -1;
			out.println(binarySearchWorms(-1, n, worm) + 1);
		}
		
		in.close();
out.close();
	}

}