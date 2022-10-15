<?php
	$stdin = STDIN;
	fscanf($stdin, "%d", $knt);
	if ($knt % 2 == 0) {
		echo 1;
		for ($i = 1; $i < $knt / 2; $i++) {
			echo 1;
		}
	} else {
		echo 7;
		for ($i = 2; $i < $knt / 2; $i++) {
			echo 1;
		}
	}
?>