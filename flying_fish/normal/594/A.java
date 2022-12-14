import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] nums = new int[n];
		for(int i=0; i<n; ++i) {
			nums[i] = sc.nextInt();
		}
		Arrays.sort(nums);
		int maxx = 1<<30;
		for(int i=0; i+n/2<n; ++i) {
			maxx = Math.min(maxx, nums[i+n/2] - nums[i]);
		}
		System.out.println(maxx);
		sc.close();
	}
}