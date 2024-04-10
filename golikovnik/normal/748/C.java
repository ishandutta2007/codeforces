import java.util.Scanner;

public class Robot {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = Integer.parseInt(in.nextLine());
		String movements = in.nextLine();
		in.close();
		int first_x = 0;
		int first_y = 0;
		int last_x = 0;
		int last_y = 0;
		int last_s = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			char movement = movements.charAt(i);
			int current_x = last_x;
			int current_y = last_y;
			if (movement == 'R') {
				current_x++;
			} else if (movement == 'L') {
				current_x--;
			} else if (movement == 'U') {
				current_y++;
			} else {
				current_y--;
			}
			int s = Math.abs(current_x-first_x) + Math.abs(current_y - first_y);
			if (s < last_s) {
				ans++;
				first_x = last_x;
				first_y = last_y;
				last_x = current_x;
				last_y = current_y;
				last_s = 1;
				continue;
			}
			last_s = s;
			last_x = current_x;
			last_y = current_y;
		}
		System.out.println(ans+1);
	}

}